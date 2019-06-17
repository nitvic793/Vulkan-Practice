
E:\VulkanSDK\1.1.106.0\Bin\glslangValidator.exe -V VertexShader.hlsl -e main -S vert -D -g --amb --hlsl-offsets --sbb 20 --suavb 30 -q -i
E:\VulkanSDK\1.1.106.0\Bin\glslangValidator.exe -V PixelShader.hlsl -e main -S frag -D -g

pause
##E:\VulkanSDK\1.1.106.0\Bin\glslangValidator.exe -V VertexShader.hlsl -e main -S vert -D -g
##E:\VulkanSDK\1.1.106.0\Bin\glslangValidator.exe -V PixelShader.hlsl -e main -S frag -D -g
##E:\Graphics\hlsl.bin\Debug\bin\dxc.exe -spirv -T vs_5_0 -E main .\VertexShader.hlsl -Fo vert.spv -fspv-reflect -Zpc -Zi
##E:\Graphics\hlsl.bin\Debug\bin\dxc.exe -spirv -T ps_5_0 -E main .\PixelShader.hlsl -Fo frag.spv -Zi