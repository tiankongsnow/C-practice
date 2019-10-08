int main()
{   
    float BMI;
    float height;
    float weight;
    while(scanf("%f %f", &height, &weight) != EOF){
        BMI = (weight / (height * height)) * 10000;
        printf("BMI is %.1f\n", BMI);
    }
    return BMI;
}
