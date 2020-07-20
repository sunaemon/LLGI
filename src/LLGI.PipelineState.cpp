
#include "LLGI.PipelineState.h"
#include "LLGI.Graphics.h"

namespace LLGI
{

PipelineState::PipelineState() { VertexLayoutSemantics.fill(0); }

void PipelineState::SetShader([[maybe_unused]] ShaderStageType stage, [[maybe_unused]] Shader* shader) {}

void PipelineState::SetRenderPassPipelineState(RenderPassPipelineState* renderPassPipelineState)
{
	SafeAddRef(renderPassPipelineState);
	renderPassPipelineState_ = CreateSharedPtr(renderPassPipelineState);
}

bool PipelineState::Compile() { return false; }

} // namespace LLGI
