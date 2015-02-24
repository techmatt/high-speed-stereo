
#include "main.h"

void ModeView2D::init(ml::ApplicationData& _app, AppState &_state)
{
    app = &_app;
    state = &_state;
    const auto &stereo = state->stereo;

    auto makeBBox = [](int xStart, int yStart, int width, int height) {
        return bbox2i(vec2i(xStart, yStart), vec2i(xStart + width, yStart + height));
    };

    canvas.init(app->graphics);
    immediateCanvas.init(app->graphics);

    canvas.addBillboard("leftCamera", makeBBox(5, 5, stereo.width, stereo.height), stereo.leftCamera.bmp, 0.9f);
    canvas.addBillboard("rightCamera", makeBBox(25 + stereo.width, 5, stereo.width, stereo.height), stereo.rightCamera.bmp, 0.9f);
}

void ModeView2D::render()
{
    immediateCanvas.clearElements();

    auto leftBox = canvas.getElementById("leftCamera").castBillboard().getBox();
    immediateCanvas.addCircle(ml::vec2f(leftBox.getMin() + leftPickedCoord), 5.0f, ml::vec4f(0.8f, 0.2f, 0.2f, 1.0f), 0.1f);

    //canvas.render();

    immediateCanvas.render();
}

void ModeView2D::keyDown(UINT key)
{
    
}

void ModeView2D::mouseDown(ml::MouseButtonType button)
{
    D3D11Canvas2D::Intersection intersection = canvas.intersectionFirst(vec2i(app->input.mouse.pos.x, app->input.mouse.pos.y));
    if (intersection.elementId == "leftCamera")
    {
        leftPickedCoord = intersection.coord;
    }
}

string ModeView2D::helpText() const
{
    string text;
    text += "Z: Synthesize random scenes|";
    return text;
}

vector< pair<string, RGBColor> > ModeView2D::statusText() const
{
    vector< pair<string, RGBColor> > result;

    result.push_back(std::make_pair(string("Status text"), RGBColor::White));

    return result;
}
