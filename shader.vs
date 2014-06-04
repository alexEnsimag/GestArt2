
// VERTEX SHADER
#version 130

// Attributs
in vec3 VertexPosition, VertexNormal;

// Uniform
uniform mat3 NormalMatrix;
uniform mat4 ModelViewMatrix, ModelViewProjectionMatrix;
uniform vec3 LightPosition;

// Sorties
smooth out vec3 EyeVector, Normal, LightDir;

invariant gl_Position;

void main ()
{
	Normal = NormalMatrix * Normal;
	vec3 Position = vec3 (ModelViewMatrix * vec4 (VertexPosition, 1.0));

	LightDir = LightPosition - Position;
	EyeVector = -Position;
	
	gl_Position = ModelViewProjectionMatrix * vec4 (VertexPosition, 1.0);
}

