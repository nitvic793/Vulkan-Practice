

struct PixelInput
{
	float4 Position				: SV_POSITION;
	float3 Color				: COLOR;
	float2 UV					: TEXCOORD0;
};

Texture2D		Texture			: register(t1); // Binding 1 (Combined Texture Sampler)
SamplerState	BasicSampler	: register(s1);

float4 main(PixelInput input)	: SV_TARGET
{
	float3 color = Texture.Sample(BasicSampler, input.UV).rgb;
	return float4(color, 1.0f);
}