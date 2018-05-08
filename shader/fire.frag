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
	int var = 10;
	float f = var;

	if (get_pixel(ivec2(0, 0)).w == 0)
	{
		vec3 color = vec3(0.4, 0., 0.1);

		for (int x = -var; x <= var; x++)
			for (int y = -var; y <= var; y++)
			{
				if (get_pixel(ivec2(x, y)).w > 0)
					f = min(f, length(vec2(x, y)));
			}
		f = f / var;
		f = 1 - f;
		gl_FragColor = vec4(color, f);
	}
	else
		gl_FragColor = pixel;
}
