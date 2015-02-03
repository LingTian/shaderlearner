// Created by inigo quilez - iq/2013
// License Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.


void main(void)
{
	vec2 p = (2.0*gl_FragCoord.xy-iResolution.xy)/min(iResolution.y,iResolution.x);
    
    float a = atan(p.x,p.y);
    float r = length(p)*(0.8+0.2*sin(0.3*iGlobalTime));
    
    float w = cos(2.0*iGlobalTime+-r*2.0);
    float h = 0.5+0.5*cos(12.0*a-w*7.0+r*8.0+ 0.7*iGlobalTime);
	
	vec3 col = vec3( length(p),
                    length(p),
                    length(p) );
	col = clamp( col, 0.0, 1.0 );
	
	vec3 bcol = mix( 0.5*vec3(1.8,0.9,1.0), vec3(1.0), 0.5+0.5*p.y );
	col = mix( col, bcol, smoothstep(-0.3,0.6,r-h) );
    gl_FragColor = vec4( col, 1.0 );
}