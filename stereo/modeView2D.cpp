
#include "main.h"

void ModeView2D::init(ml::ApplicationData& _app, AppState &_state)
{
    app = &_app;
    state = &_state;
}

void ModeView2D::render()
{
    //state->renderer.renderViewPlane()
}

void ModeView2D::keyDown(UINT key)
{
    
}

void ModeView2D::mouseDown(ml::MouseButtonType button)
{

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
