#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

uniform sampler2D texture0;
uniform int scale;
uniform float rChannel;
uniform float gChannel;
uniform float bChannel;

// Final color
out vec4 finalColor;

void main()
{
    float val = texture2D(texture0, fragTexCoord / scale).x;

    if (val <= 0.40)
    {
        // BLUE
        finalColor = vec4( rChannel * 0.1, gChannel * val, bChannel * (val+0.4), 1.0);
    }
    else if (val > 0.40 && val < 0.70)
    {
        // GREEN
         finalColor = vec4(rChannel * -val, gChannel * val, bChannel * (val-0.7), 1.0);
    }
    else
    {
        // GRAY
        finalColor = vec4( rChannel * (val-0.1), gChannel * (val-0.2), bChannel * 0.3, 1.0);
    }
}