#version 130

uniform sampler2D texture;

vec2 step = vec2(1., 1.) / textureSize(texture, 0);

vec4	get_pixel(ivec2 i)
{
	vec2 pos = vec2(gl_TexCoord[0].xy + i * step);

	return (texture2D(texture, pos));
}
void main()
{
	vec2	pos = gl_TexCoord[0].xy;
	vec4	pixel = texture2D(texture, pos);

	pixel.x = pixel.x * 4;
	gl_FragColor = pixel / 2;
}
