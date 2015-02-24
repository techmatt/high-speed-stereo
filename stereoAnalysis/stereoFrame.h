
struct PixelDescriptor
{
    PixelDescriptor()
    {
        valid = true;
    }
    bool valid;
    vector<BYTE> data;
};

struct StereoCameraHistory
{
    void buildDescriptor(size_t x, size_t y, PixelDescriptor &result) const;

    Bitmap bmp;

    //
    // 0 = most recent image, larger values go into the past
    //
    vector< Grid2<BYTE> > images;
};

struct StereoFrame
{
    void initSingle(const string &filenameLeft, const string &filenameRight);

    Grid2<double> computeDisparity() const;

    StereoCameraHistory leftCamera, rightCamera;
    int width, height;

private:
    static double compareDescriptors(const PixelDescriptor &a, const PixelDescriptor &b)
    {
        if (!a.valid || !b.valid)
            return std::numeric_limits<double>::infinity();

        double result = 0.0;
        const size_t length = a.data.size();
        const BYTE *aData = &a.data[0];
        const BYTE *bData = &b.data[0];
        for (size_t i = 0; i < length; i++)
        {
            int diff = (int)aData[i] - (int)bData[i];
            result += diff * diff;
        }
        return result;
    }

    vector<double> computeDisparityGraph(size_t xLeft, size_t yLeft) const;
};