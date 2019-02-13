#version 130

uniform sampler2D texture;

void main()
{
	vec2	pos = gl_TexCoord[0].xy;
	vec4	pixel = texture2D(texture, pos);

	gl_FragColor = pixel;
}
