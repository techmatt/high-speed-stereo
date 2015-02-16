
#include "main.h"

void ModeView3D::init(ml::ApplicationData& _app, AppState &_state)
{
    app = &_app;
    state = &_state;
}

void ModeView3D::render()
{

}

void ModeView3D::keyDown(UINT key)
{

}

void ModeView3D::mouseDown(ml::MouseButtonType button)
{

}

string ModeView3D::helpText() const
{
    string text;
    text += "Z: Synthesize random scenes|";
    return text;
}

vector< pair<string, RGBColor> > ModeView3D::statusText() const
{
    vector< pair<string, RGBColor> > result;

    result.push_back(std::make_pair(string("Status text"), RGBColor::White));

    return result;
}
