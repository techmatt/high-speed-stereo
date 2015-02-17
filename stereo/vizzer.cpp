
#include "main.h"

const bool runUIDebugger = false;

void Vizzer::init(ml::ApplicationData& app)
{
    ParameterFile params;
    const string file = "../../params.txt";
    if (!ml::util::fileExists(file))
    {
        std::cerr << "Parameter file not found: " << file << endl;
        exit(-1);
        return;
    }
    params.addParameterFile(file);

    app.graphics.castD3D11().setCullMode(D3D11_CULL_NONE);

    initStereoParams(params);

    state.modeView2D.init(app, state);
    state.modeView3D.init(app, state);

    m_font.init(app.graphics, "Calibri");

    state.camera = ml::Camera<float>("3.1007 -4.67105 6.07874 1 0 0 0 0.836286 -0.548293 0 0.548293 0.836286 0 0 1 60 1.39502 0.01 1000");
    state.camera.updateAspectRatio((float)app.window.width() / app.window.height());

    app.graphics.castD3D11().captureBackBuffer();

    state.renderer.init(app.graphics.castD3D11());

    if (runUIDebugger)
    {
        cout << "Run the UI under the debugger, then press any key" << endl;
        std::cin.get();
        state.ui.init("", "UIStereo");
    }
    else
        state.ui.init("../UIStereo.exe", "UIStereo");

    state.mode = VizzerMode2DView;
    state.updateModeInterface();

    registerEventHandlers(app);

    state.stereo.initSingle(stereoParams().dataDir + "testA/left.png", stereoParams().dataDir + "testA/right.png");
}

void Vizzer::registerEventHandlers(ml::ApplicationData& app)
{
    state.eventMap.registerEvent("terminate", [&](const vector<string> &params) {
        PostQuitMessage(0);
    });
    state.eventMap.registerEvent("mode", [&](const vector<string> &params) {
        state.mode = modeFromName(params[1]);
        state.updateModeInterface();
    });
}

void Vizzer::render(ml::ApplicationData& app)
{
    m_timer.frame();

    state.eventMap.dispatchEvents(state.ui);

    state.modeInterface->render();

    vector< pair<string, RGBColor> > lines;

    lines.push_back(std::make_pair("FPS: " + to_string(m_timer.framesPerSecond()), RGBColor::Red));
    lines.push_back(std::make_pair("[tab] Mode: " + modeName(state.mode), RGBColor::Red));

    for (const auto &line : state.modeInterface->statusText())
        lines.push_back(line);

    m_font.drawStrings(app.graphics, lines, ml::vec2i(10, 5), 24.0f, 27);
}

void Vizzer::resize(ml::ApplicationData& app)
{
    state.camera.updateAspectRatio((float)app.window.width() / app.window.height());
    app.graphics.resize(app.window.width(), app.window.height());
    //m_font.reset(app.graphics);
}

void Vizzer::keyDown(ml::ApplicationData& app, UINT key)
{
    state.modeInterface->keyDown(key);

    if (key == KEY_F) app.graphics.castD3D11().toggleWireframe();

    if (key == KEY_TAB)
    {
        state.mode = VizzerMode(((int)state.mode + 1) % (int)VizzerModeCount);
        state.updateModeInterface();
    }
}

void Vizzer::keyPressed(ml::ApplicationData& app, UINT key)
{
    state.modeInterface->keyPressed(key);

    float distance = 0.2f;
    float theta = 2.5f;

    if (key == KEY_W) { state.camera.move(distance); }
    if (key == KEY_S) { state.camera.move(-distance); }
    if (key == KEY_A) { state.camera.strafe(-distance); }
    if (key == KEY_D) { state.camera.strafe(distance); }
}

void Vizzer::mouseDown(ml::ApplicationData& app, ml::MouseButtonType button)
{
    state.modeInterface->mouseDown(button);
}

void Vizzer::mouseWheel(ml::ApplicationData& app, int wheelDelta)
{
    state.modeInterface->mouseWheel(wheelDelta);

    const float distance = 0.002f;
    state.camera.move(distance * wheelDelta);
}

void Vizzer::mouseMove(ml::ApplicationData& app)
{
    state.modeInterface->mouseMove();

    const float distance = 0.01f;
    const float theta = 0.25f;

    ml::vec2i posDelta = app.input.mouse.pos - app.input.prevMouse.pos;

    if (app.input.mouse.buttons[ml::MouseButtonRight])
    {
        state.camera.strafe(distance * posDelta.x);
        state.camera.jump(-distance * posDelta.y);
    }

    if (app.input.mouse.buttons[ml::MouseButtonLeft])
    {
        state.camera.lookRight(-theta * posDelta.x);
        state.camera.lookUp(theta * posDelta.y);
    }
}
