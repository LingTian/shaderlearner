
vec2 resolution;
float time;
varying vec4 v_fragmentColor;
uniform sampler2D CC_Texture0;
varying vec2 v_texCoord;

void main( void ) {
    resolution=vec2(1024.0,768.0);
    time=CC_Time[1];
	vec2 position = ( gl_FragCoord.xy / resolution.xy );
	vec3 color=vec3((sin(time)+1./2.), position.x, position.y);
    
	gl_FragColor = vec4( color , 1.0 )* texture2D(CC_Texture0, v_texCoord);
    
}
