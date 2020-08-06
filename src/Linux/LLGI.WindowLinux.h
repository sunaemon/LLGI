#pragma once

#include "../LLGI.Base.h"
#ifndef LLGI_USE_WAYLAND
#include <X11/Xlib-xcb.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#else
#endif
#include <locale.h>
#include <string>

namespace LLGI
{

class WindowLinux : public Window
{
private:
#ifndef LLGI_USE_WAYLAND
	Display* display_ = nullptr;
	::Window window_;
	GC gc_;
	Atom wm_delete_window_;
#endif
	bool closed_ = false;
	std::string title_;
	Vec2I windowSize_;

public:
	WindowLinux() = default;

	~WindowLinux() override;

	bool Initialize(const char* title, const Vec2I& windowSize);

	bool DoEvent();

	void Terminate();

#ifndef LLGI_USE_WAYLAND
	Display*& GetDisplay() { return display_; }
	::Window& GetWindow() { return window_; }
#endif

	bool OnNewFrame() override;

	void* GetNativePtr(int32_t index) override;

	Vec2I GetWindowSize() const override { return windowSize_; };
};

} // namespace LLGI
