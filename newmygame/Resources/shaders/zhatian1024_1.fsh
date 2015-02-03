// Shader taken from: http://webglsamples.googlecode.com/hg/electricflower/electricflower.html

#ifdef GL_ES
precision mediump float;
#endif
float outerSphereRad = 3.5;
vec2 resolution;
varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
uniform sampler2D CC_Texture0;
float time;
#ifdef GL_ES
precision mediump float;
#endif
void main( void ) {
    resolution=vec2(1024.0,768.0);
    time= abs(sin(CC_Time[1]))*.5;
	vec2 position = (gl_FragCoord.yx/resolution.yx) - 0.5;
	
	float px = 0.2 * (position.x+0.8)*sin(900.0*position.x-20.0*pow(time, 0.55)*5.0);
	float py = 1.0 / (500.0 * abs(position.y - px));
	
	py += 1./length(25.*length(position - vec2(0, position.y)));
	
	py += 1./length(25.*length(position - vec2(position.x, 0)));
	
	gl_FragColor = vec4( py, (position.x + 0.1) * py, py, 1.0)* texture2D(CC_Texture0, v_texCoord);
    
	
}