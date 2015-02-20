
#include "Main.h"

void StereoCameraHistory::buildDescriptor(size_t x, size_t y, PixelDescriptor &result) const
{
    const int windowSize = 4;
    const size_t descriptorLength = ml::math::square(windowSize * 2 + 1);

    result.valid = true;

    if (result.data.size() != descriptorLength)
        result.data.resize(descriptorLength);

    const Grid2<BYTE> &image = images[0];

    if (x <= windowSize + 1 || x >= image.dimX() - windowSize - 1 ||
        y <= windowSize + 1 || y >= image.dimY() - windowSize - 1)
    {
        result.valid = false;
        return;
    }

    const BYTE *imagePtr = image.ptr();
    BYTE *resultPtr = &result.data[0];
    const size_t imageWidth = image.dimX();

    UINT resultIndex = 0;
    for (int yOffset = -windowSize; yOffset <= windowSize; yOffset++)
        for (int xOffset = -windowSize; xOffset <= windowSize; xOffset++)
        {
            int curX = (int)x + xOffset;
            int curY = (int)x + yOffset;
            resultPtr[resultIndex++] = imagePtr[curX * imageWidth + curY];
        }
}

void StereoFrame::initSingle(const string &filenameLeft, const string &filenameRight)
{
    Bitmap bmpLeft = ml::LodePNG::load(filenameLeft);
    Bitmap bmpRight = ml::LodePNG::load(filenameRight);

    width = bmpLeft.dimX();
    height = bmpLeft.dimY();

    leftCamera.images.push_back(Grid2<BYTE>(width, height, [&](size_t x, size_t y) { return bmpLeft(x, y).r; }));
    rightCamera.images.push_back(Grid2<BYTE>(width, height, [&](size_t x, size_t y) { return bmpRight(x, y).r; }));
}

Grid2<double> StereoFrame::computeDisparity() const
{
    return Grid2 < double >();
}

vector<double> StereoFrame::computeDisparityGraph(size_t xLeft, size_t yLeft) const
{
    PixelDescriptor leftDescriptor, rightDescriptor;
    leftCamera.buildDescriptor(xLeft, yLeft, leftDescriptor);

    vector<double> result(width);
    for (size_t xRight = 0; xRight < width; xRight++)
    {
        rightCamera.buildDescriptor(xRight, yLeft, rightDescriptor);
        result[xRight] = compareDescriptors(leftDescriptor, rightDescriptor);
    }
    return result;
}