LAB TASK 💻: <br/> <br/>
  ▾ Write a C program to calculate the time it takes for an object to reach the ground, it's velocity upon impact, and its kinetic energy at the moment of impact, given a user-specified height from which the object is dropped. <br/>

    Time Calculations: 
        • Formula: t = √2h/g
        • Variable: 
            • t = time to reach the ground (seconds,s) 
            • h = height of the drop (meters, m)
            • g = acceleration due to gravity (9.8 m/s^2) 
  
    Velocity Calculations: 
        • Formula: v = g x t
        • Variables:
            • v = velocity upon ground impact (m/s)
            • g = acceleration due to gravity (9.8 m/s^2)
            • t = time to reach the ground (s)

    Kinetic Energy Calculations:
        • Formula: e = 1/2mv^2
        • Variables:
            • e = kinetic energy at impact (Joules, J)
            • m = mass of the object (kilograms, kg)
            • v = velocity upon ground impact (m/s)

  <br/> ▾ PROGRAM REQUIREMENTS:
  
        • Use 'float' or 'double' types for all variables. <br/>
        • Prompt the user to input the object's mass (kg) and the height of the drop (m). <br/>
        • Utulize the given formulas to compute the time taken, and kinetic energy, storing each result in a variable with a meaningful name.
        • Display the results formatted as follows: <br/>
            • "The time taken by an object weighing ___ kg to reach the ground when dropped from a height of __ meters is __ seconds."
            • "The velocity of the object when it hits the ground = ___ m/s."
            • "The kinetic energy at the momenet of impact with the ground is ___ Joules."
        • Ensure the program compilse and runs correctly on the Snowball server.
  


