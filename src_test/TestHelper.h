
#pragma once
#include "test.h"
#include <functional>
#include <map>
#include <memory>
#include <stdint.h>
#include <string>
#include <vector>

struct InternalTestHelper;

struct ParsedArgs
{
	LLGI::DeviceType Device = LLGI::DeviceType::Default;
	std::string Filter;
};

class TestHelper
{
private:
	static std::shared_ptr<InternalTestHelper> Get();

public:
	static ParsedArgs ParseArg(int argc, char* argv[]);

	static void WriteDummyTexture(LLGI::Color8* data, LLGI::Vec2I size);

	static std::vector<uint8_t> LoadData(const char* path);

	static std::vector<uint8_t> LoadDataWithoutRoot(const char* path);

	static void SetRoot(const char* root);

	/**
		@brief create a rectangle
	*/
	static void CreateRectangle(LLGI::Graphics* graphics,
								const LLGI::Vec3F& ul,
								const LLGI::Vec3F& lr,
								const LLGI::Color8& cul,
								const LLGI::Color8& clr,
								std::shared_ptr<LLGI::VertexBuffer>& vb,
								std::shared_ptr<LLGI::IndexBuffer>& ib);

	static void CreateShader(LLGI::Graphics* graphics,
							 LLGI::DeviceType deviceType,
							 const char* vsBinaryPath,
							 const char* psBinaryPath,
							 std::shared_ptr<LLGI::Shader>& vs,
							 std::shared_ptr<LLGI::Shader>& ps);

	static void Run(const ParsedArgs& args);

	static void RegisterTest(const char* name, std::function<void(LLGI::DeviceType)> func);

	static bool GetIsCaptureRequired();
	static void SetIsCaptureRequired(bool required);
	static void Dispose();
};

struct TestRegister
{
	TestRegister(const char* name, std::function<void(LLGI::DeviceType)> func) { TestHelper::RegisterTest(name, func); }
};

class Bitmap2D
{
public:
	struct Color
	{
		uint8_t r, g, b, a;
	};

	Bitmap2D(const std::vector<uint8_t>& data, int width, int height, bool bgraFormat);
	Bitmap2D(const char* filePath);

	Color GetPixel(int x, int y) const;
	void Save(const char* filePath);

	/**
	 * @param[in]   colorThreshold : Tolerance threshold for each color element. (Absolute value)
	 * @return      Match rate (%)
	 */
	static int CompareBitmap(const Bitmap2D& bmp1, const Bitmap2D& bmp2, int colorThreshold);

private:
	Color mixPixels(int x, int y) const;

	std::vector<uint8_t> data_; // RGBA
	int width_;
	int height_;
};
