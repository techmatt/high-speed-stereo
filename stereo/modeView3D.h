
struct ModeView3D : public VizzerModeInterface
{
    void init(ml::ApplicationData& _app, AppState &_state);
    void render();
    void keyDown(UINT key);
    void mouseDown(ml::MouseButtonType button);

    string helpText() const;
    vector< pair<string, RGBColor> > statusText() const;

    ml::ApplicationData *app;
    AppState *state;
};
