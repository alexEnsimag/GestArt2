#version 130

// Precision qualifier
precision highp float;

// Entrées
smooth in vec3 EyeVector, Normal, LightDir;

// Uniform
uniform vec3 LightDiffuse, MaterialDiffuse;

// Sortie
out vec4 Color;

void main()
{
	vec3 N = normalize (Normal);
	vec3 L = normalize (LightDir);
	float nDotL = max (dot (N, L), 0.0);
	
	Color = vec4 (LightDiffuse * MaterialDiffuse * nDotL, 1.0);
}




