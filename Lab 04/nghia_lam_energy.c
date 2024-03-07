#include <math.h>
#include <stdio.h>

int main(){
    float mass;
    printf("Enter the mass of the object in kilograms: ");
    scanf("%f", &mass);
    
    float height;
    printf("Enter the height of the drop in meters: ");
    scanf("%f", &height);
    
    float g = 9.8;
    float time = sqrt(2 * (height/g));
    float velocity = g * time;
    float KE = (0.5 * mass) * (velocity * velocity);
    
    printf("The time taken by an object weighing %.2f to reach the ground when dropped from a height of %.2f meters is %.2f seconds.\n", mass, height, time);
    printf("The velocity of the object when it hits the ground = %.2f m/s.\n", velocity);
    printf("The kinetic energy at the moment of impact with the ground is %.2f Joules.\n", KE);
    return 0;
}
