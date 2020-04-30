#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahrehnheit_to_celsius(float fahrenheit) {
    return (5.0/9.0)*(fahrenheit-32.0);
}

int version_with_while_loop() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = fahrehnheit_to_celsius(fahr);
        printf("%.0f\t%.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}

int version_with_for_loop() {
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        printf("%.0d\t%.1f\n", fahr, fahrehnheit_to_celsius(fahr));
    }
    return 0;
}

int main() {
    // return version_with_while_loop();
    return version_with_for_loop();
}
