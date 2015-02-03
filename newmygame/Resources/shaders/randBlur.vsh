// Shader is inspired & modified from: http://coding-experiments.blogspot.ca/2010/06/frosted-glass.html
#ifdef GL_ES
precision mediump float;
#endif

attribute vec4 a_position;
attribute vec4 a_color;
attribute vec2 a_texCoord;

varying vec2 v_texCoord;

void main()
{
    gl_Position = CC_PMatrix * a_position;
   
	v_texCoord = a_texCoord;
    
}