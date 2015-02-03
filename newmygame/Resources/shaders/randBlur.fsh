// Shader is inspired & modified from: http://coding-experiments.blogspot.ca/2010/06/frosted-glass.html

#ifdef GL_ES
precision mediump float;
#endif

varying lowp vec2 v_texCoord;

uniform sampler2D u_texture;

float rand(vec2 co)
{
    return fract(sin(dot(co.xy ,vec2(100,100))) +
                 cos(dot(co.xy ,vec2(50,50))) * 5.0);
}

void main()
{
    vec2 rnd = vec2(0.0);
    rnd = vec2(rand(v_texCoord),rand(v_texCoord));
    gl_FragColor = texture2D(u_texture, v_texCoord+rnd*0.02);
}
