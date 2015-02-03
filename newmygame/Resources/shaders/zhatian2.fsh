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
    resolution=vec2(2048.0,1536.0);
    time= sin(CC_Time[1])*.5;
	vec2 position = (gl_FragCoord.yx/resolution.yx) - 0.5;
	
	float px = 0.2 * (position.x+0.8);
	float py = 2.0 / (500.0 * abs(position.y - px)*time);
    py += 2.0 / (500.0 * abs(position.y + px)*time);
    
    //py += 1.0 / (300.0 * abs(position.y - px));
    
   // py += 1.0 / (300.0 * abs(position.y + px));
    
   // py += 5.0 / (100.0 * abs(position.y - px));
    
    //py += 5.0 / (100.0 * abs(position.y + px));
    
	py += (1.+time)/length(25.*length(position - vec2(0, position.y)));
	
	py += (1.+time)/length(25.*length(position - vec2(position.x, 0)));


	gl_FragColor = vec4( py,  0.3 * py, 0.3 *py, 1.0)* texture2D(CC_Texture0, v_texCoord);
    
	
}