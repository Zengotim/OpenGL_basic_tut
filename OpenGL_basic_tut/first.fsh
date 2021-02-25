#version 330 core

out vec4 FragColor;
in vec3 ourColor;
uniform vec4 colorMod;

void main()
{
   //float red, blue, green;
   //red = colorMod.x; //mod((ourColor.x + colorMod.x/2.0f), 1.0f);
   //green = colorMod.y; //mod((ourColor.z + colorMod.y/2.0f), 1.0f);
   //blue = colorMod.z; //mod((ourColor.y + colorMod.z/2.0f), 1.0f);
   

   FragColor = colorMod;
};