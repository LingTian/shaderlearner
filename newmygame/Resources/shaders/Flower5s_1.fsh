// Shader from http://www.iquilezles.org/apps/shadertoy/

#ifdef GL_ES
precision highp float;
#endif
varying vec2 v_texCoord;
uniform sampler2D CC_Texture0;

vec2 center;
vec2 resolution;

//float u( float x ) { return 0.5+0.5*sign(x); }
float u( float x ) { return (x>0.0)?1.0:0.0; }
//float u( float x ) { return abs(x)/x; }

void main(void)
{
    resolution=vec2(1136.0/2.,640.0/2.);
    center=vec2(1136.0/2.,640.0/2.);
    
	float time = CC_Time[1];
	vec2 p = 2.0 * (gl_FragCoord.xy-center) / resolution.xy;
	
	float a = atan(p.x,p.y);
	float r = length(p)*.75;

	float w = sin(3.1415927*time);
	float h = 0.5+0.5*cos(1.0*a-w*7.0+r*8.0);
gl_FragColor = vec4(
		h,
		h,
		h,
		1.0) * texture2D(CC_Texture0, v_texCoord);
}