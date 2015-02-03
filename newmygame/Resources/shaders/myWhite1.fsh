// Shader is inspired from http://www.iquilezles.org/apps/shadertoy/

#ifdef GL_ES
precision mediump float;
#endif

uniform float time;
vec2 resolution;
float c;
vec2 position;

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
uniform sampler2D CC_Texture0;

void main( void ) {
    resolution=vec2(1024.0,768.0);
    vec2 flame;
    flame.x=sin(CC_Time[1])*1.0;
    flame.y=sin(CC_Time[1])*1.0;
    
    
    position = ( gl_FragCoord.xy / resolution.xy );
    position = position - 0.5;  //here I minus 0.5 because CCzero point on iPad is left courner.
    position.x *= resolution.x/resolution.y;
    position.x *= flame.x;
    position.y *= flame.y;
    c = sqrt(position.x*position.x+position.y*position.y);
    
    gl_FragColor = vec4(vec2(1.0 - c*2.0),c, 1.0-c*3. )* texture2D(CC_Texture0, v_texCoord);
    
}

