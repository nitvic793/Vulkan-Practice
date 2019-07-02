#pragma warning(disable:G8E3704CA)

struct PixelInput
{
	float4 Position				: SV_POSITION;
	float3 Color				: COLOR;
	float3 Normal				: NORMAL;
	float2 UV					: TEXCOORD0;
};

struct DirectionalLight
{
	float3 Direction;
	float3 Color;
};

[[vk::binding(3)]]
cbuffer LightBuffer				: register(b0)
{
	DirectionalLight DirLight;
};

[[vk::binding(1)]]
Texture2D		Texture			: register(t0); // Binding 1 (Combined Texture Sampler)
[[vk::binding(1)]]
SamplerState	BasicSampler	: register(s0);

float4 main(PixelInput input)	: SV_TARGET
{
	float3 dirToLight = normalize(-DirLight.Direction);
	float NdotL = saturate(dot(input.Normal, dirToLight));
	float3 lightAmount = DirLight.Color * NdotL + float3(0.1f, 0.1f, 0.1f);
	float3 color = Texture.Sample(BasicSampler, input.UV).rgb;
	return float4(color * lightAmount, 1.0f);
}