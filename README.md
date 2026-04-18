# Guard Logic Challenge

## Approach

I primarily work with Java, but I implemented this solution in C++ to demonstrate adaptability.

I modeled each door as an object with attributes such as safety, trap presence, and visit status.

Instead of using simple conditional statements, I designed a scoring-based decision system:
- Safe doors are given highest priority
- Doors without traps are preferred
- Unvisited doors are prioritized

Each door is evaluated using this scoring logic, and the system selects the door with the highest score.

Additionally, I included output explanations to clearly indicate why a particular door was chosen.

## Features
- Object-Oriented Design
- Scoring-based decision logic
- Multiple test cases
- Clear output explanation
