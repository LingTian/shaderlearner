#ifdef GL_ES
precision mediump float;
#endif
// The shader is inspired and modified from cocos2d custom shader tutorial                                 http://www.raywenderlich.com/10862/how-to-create-cool-effects-with-custom-shaders-in-opengl-es-2-0-and-cocos2d-2-x
varying vec2 v_texCoord;
uniform sampler2D u_texture;
void main()
{
    // pixel size
    vec2 onePixel = vec2(1.0 / 480.0, 1.0 / 320.0);
    
    // get v_texCoordate
    vec2 texCoord = v_texCoord;
    
    // exactly step follow the idea
    vec4 color;
    color.rgb = vec3(0.5);
    color -= texture2D(u_texture, texCoord - onePixel) * 5.0;
    color += texture2D(u_texture, texCoord + onePixel) * 5.0;
    // grayscale
    color.rgb = vec3((color.r + color.g + color.b) / 3.0);
    gl_FragColor = vec4(color.rgb, 1);
}