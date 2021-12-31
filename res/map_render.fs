#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

uniform sampler2D texture0;
uniform int scale;

out vec4 finalColor;

void main()
{
    float val = texture2D(texture0, fragTexCoord / scale).x;

    if (val <= 0.40)
    {
        // BLUE
        finalColor = vec4( 0.1, val,  val+0.4, 1.0);
    }
    else if (val > 0.40 && val < 0.70)
    {
        // GREEN
         finalColor = vec4(-val, val,  val-0.7, 1.0);
    }
    else
    {
        // GRAY
        finalColor = vec4(val-0.1, val-0.2, 0.3, 1.0);
    }
}