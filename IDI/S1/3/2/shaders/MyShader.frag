#version 330 core
out vec4 FragColor;

void main() {
    if (int(mod(gl_FragCoord.y/10., 2.0)) == 0) discard;
    else {
        if (gl_FragCoord.x < 354. && gl_FragCoord.y < 354.) FragColor = vec4(1.,1.,0.,0);
        else if (gl_FragCoord.x < 354. && gl_FragCoord.y > 354.) FragColor = vec4(1.,0.,0.,1);
        else if (gl_FragCoord.x > 354. && gl_FragCoord.y > 354.) FragColor = vec4(0.,0.,1.,1);
        else if (gl_FragCoord.x > 354. && gl_FragCoord.y < 354.) FragColor = vec4(0.,1.,0.,1);
    }
}