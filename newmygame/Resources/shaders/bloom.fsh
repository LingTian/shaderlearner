#ifdef GL_ES
precision mediump float;
#endif

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

uniform vec2 resolution;
uniform sampler2D CC_Texture0;


const float blurSize = 1.0/512.0;
const float intensity = 0.35;
void main()
{
   vec4 sum = vec4(0);
   vec2 texcoord = v_texCoord.xy;
   int j;
   int i;

  	sum += texture2D(CC_Texture0, v_texCoord - 4.0 * blurSize) * 0.063327;
	sum += texture2D(CC_Texture0, v_texCoord - 3.0 * blurSize) * 0.093095;
	sum += texture2D(CC_Texture0, v_texCoord - 2.0 * blurSize) * 0.122589;
	sum += texture2D(CC_Texture0, v_texCoord - 1.0 * blurSize) * 0.144599;
	sum += texture2D(CC_Texture0, v_texCoord                 ) * 0.152781;
	sum += texture2D(CC_Texture0, v_texCoord + 1.0 * blurSize) * 0.144599;
	sum += texture2D(CC_Texture0, v_texCoord + 2.0 * blurSize) * 0.122589;
	sum += texture2D(CC_Texture0, v_texCoord + 3.0 * blurSize) * 0.093095;
	sum += texture2D(CC_Texture0, v_texCoord + 4.0 * blurSize) * 0.063327;

    sum += texture2D(CC_Texture0, v_texCoord);
    gl_FragColor = sum*intensity + texture2D(CC_Texture0, texcoord);
    //gl_FragColor=sum * abs(sin(CC_Time[1])) + texture2D(CC_Texture0, texcoord);
    return;
}