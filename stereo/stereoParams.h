
struct StereoParams
{
    StereoParams()
    {
        memset(this, 0, sizeof(StereoParams));
    }
    void load(const ParameterFile &params)
    {
        params.readParameter("dataDir", dataDir);
    }

    string dataDir;
};

extern StereoParams g_stereoParams;

inline const StereoParams& stereoParams()
{
    return g_stereoParams;
}

inline StereoParams& mutableStereoParams()
{
    return g_stereoParams;
}

inline void initStereoParams(const ParameterFile &params)
{
    g_stereoParams.load(params);
}
