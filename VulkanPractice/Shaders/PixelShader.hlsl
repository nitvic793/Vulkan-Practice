#pragma warning(disable:G8E3704CA)

struct PixelInput
{
	float4 Position				: SV_POSITION;
	float3 Color				: COLOR;
	float2 UV					: TEXCOORD0;
}; 
 
[[vk::binding(1)]]
Texture2D		Texture			: register(t0); // Binding 1 (Combined Texture Sampler)
[[vk::binding(1)]]
SamplerState	BasicSampler	: register(s0);

float4 main(PixelInput input)	: SV_TARGET 
{
	float3 color = Texture.Sample(BasicSampler, input.UV).rgb;
	return float4(color, 1.0f);
}