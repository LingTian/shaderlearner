// Shader from http://www.iquilezles.org/apps/shadertoy/

#ifdef GL_ES
precision highp float;
#endif

vec2 center;
vec2 resolution;
varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
uniform sampler2D CC_Texture0;

void main(void)
{
    resolution=vec2(1024.0,768.0);
    center=vec2(1024.0,768.0);
    
    float time = CC_Time[1];
    vec2 p = 2.0 * (gl_FragCoord.xy - center.xy) / resolution.xy;
    vec2 cc = vec2( cos(.25*time), sin(.25*time*1.423) );

    float dmin = 1000.0;
    vec2 z  = p*vec2(1.33,1.0);
    for( int i=0; i<64; i++ )
    {
        z = cc + vec2( z.x*z.x - z.y*z.y, 2.0*z.x*z.y );
        float m2 = dot(z,z);
        if( m2>100.0 ) break;
        dmin=min(dmin,m2);
        }

    float color = sqrt(sqrt(dmin))*1.7;
    gl_FragColor = vec4(color,color,color,1.0) * texture2D(CC_Texture0, v_texCoord);
}

