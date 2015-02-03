// by maq/floppy
vec3 flower(vec2 p, float m)
{
   	vec3 col=vec3(0.0);
   	p -= vec2(1.5-0.2*sin(iGlobalTime*m),1.5);
   	float r = sqrt(dot(p,p));
   	float f=1.1;
   	float listki=5.0;
  	float at = atan(p.y/p.x);
   	float phi =  at+(sin(iGlobalTime*m)-sin(iGlobalTime*m+0.4)*sin(r));
	float phi2 = at+sin(iGlobalTime*m*1.0+0.3)-sin(iGlobalTime*m*1.0+0.6)*sin(r);
    
  	if(r<exp(r*2.6)*0.1+(0.01+abs(sin(listki*phi))))
        f=r;
   	else
        col = mix( vec3(0.9,0.9,0.9), vec3(0.9,0.7,0.7),f) ;
    
   	if(r<0.1+abs(sin(listki*phi2+(1.0+sin(iGlobalTime))*0.5)))
   	{
        f = r;
        col = mix( vec3(0.97+0.0025*m,0.97+0.0025*m,0), vec3(1,1,1), 10.0*f) ;
   	}
   	return col;
}

void main(void)
{
	vec2 p = 1.4*gl_FragCoord.xy / iResolution.xy;
	p.y*=0.8;
	p.x-=0.1;
	vec2 cp=p-vec2(1.1,0.5);
	vec3 col = 0.01*vec3(0.2/dot(cp,cp),0.2/dot(cp,cp),0.1/dot(cp,cp));
   	col += flower((p.xy+vec2(0,0))*4.2,2.5);
   	col += flower((p.xy+vec2(-0.45,-0.4))*4.5,3.2);
   	col += flower((p.xy+vec2(0.13,-0.4))*4.1,3.0);
   	col += flower((p.xy+vec2(-0.6,-0.1))*8.2,3.1);
	gl_FragColor = vec4(col,1.0);
}













#define N 10.
float t = iGlobalTime;
void main(void) {
    vec2 uv = 2.*(gl_FragCoord.xy / iResolution.y -vec2(.9,.5));
    float r = length(uv), a = atan(uv.y,uv.x);
    float i = floor(r*N);
    a *= floor(pow(128.,i/N)); 	 a += 20.*sin(.5*t)+123.34*i-100.*(r-0.*i/N)*cos(.5*t);
    r +=  (.5+.5*cos(a)) / N;    r = floor(N*r)/N;
	gl_FragColor = (1.0-r)*vec4(.5,1.,1.5,1.);
}