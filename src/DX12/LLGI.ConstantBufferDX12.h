
#pragma once

#include "../LLGI.ConstantBuffer.h"
#include "LLGI.BaseDX12.h"
#include "LLGI.GraphicsDX12.h"

using namespace DirectX;

namespace LLGI
{

class ConstantBufferDX12 : public ConstantBuffer
{
private:
	std::shared_ptr<GraphicsDX12> graphics_;

	ID3D12Resource* constantBuffer = nullptr;

	uint8_t* mapped = nullptr;

public:
	bool Initialize(GraphicsDX12* graphics, int32_t size);

	ConstantBufferDX12();
	virtual ~ConstantBufferDX12();

	virtual void* Lock();
	virtual void* Lock(int32_t offset, int32_t size);
	virtual void Unlock();
	virtual int32_t GetSize();
};

} // namespace LLGI