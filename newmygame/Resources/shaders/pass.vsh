                                         
#ifdef GL_ES                                  
precision lowp float;                         
#endif                                        
                                              
attribute vec4 a_position;                    
attribute vec2 a_texCoord;                    
attribute vec4 a_color;                       
                                              
varying  vec2 v_texCoord;                     
                                              
varying vec4 v_color;                         
                                              
void main() {                                 
    v_color = a_color;                        
    gl_Position = CC_MVPMatrix * a_position;  
    v_texCoord = a_texCoord;                  
}                                             

