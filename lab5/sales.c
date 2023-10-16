#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_MONTHS 12


struct SalesData {
    char month[10];
    double sales;
};

void readMonthlySales(double sales[NUM_MONTHS], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening the file");
        exit(1);
    }

    for (int i = 0; i < NUM_MONTHS; i++) {
        if (fscanf(file, "%lf", &sales[i]) != 1) {
            fprintf(stderr, "Error reading sales data from the file");
            exit(1);
        }
    }

    fclose(file);
}

void calculateSalesSummary(double sales[NUM_MONTHS], double *min, double *max, double *avg) {
    *min = sales[0];
    *max = sales[0];
    *avg = sales[0];

    for (int i = 1; i < NUM_MONTHS; i++) {
        if (sales[i] < *min) {
            *min = sales[i];
        }
        if (sales[i] > *max) {
            *max = sales[i];
        }
        *avg += sales[i];
    }

    *avg /= NUM_MONTHS;
}

void generateSalesReport(double sales[NUM_MONTHS]) {
    printf("Monthly sales report for 2022:\n");
    printf("Month\tSales\n");
    const char *monthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%-12s\t$%.2lf\n", monthNames[i], sales[i]);
    }
}

void generateMovingAverageReport(double sales[NUM_MONTHS]) {
    printf("\nSix-Month Moving Average Report:\n");
    printf("Month Range Average\n");
    const char *monthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    for (int i = 0; i <= NUM_MONTHS - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s - %s   \t$%.2lf\n", monthNames[i], monthNames[i + 5], sum / 6);
    }
}


int compareSales(const void *a, const void *b) {
    return ((struct SalesData *)b)->sales - ((struct SalesData *)a)->sales;
}

void generateHighestToLowestReport(double sales[NUM_MONTHS]){
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };


    struct SalesData salesData[NUM_MONTHS];
    for (int i = 0; i < NUM_MONTHS; i++) {
        strcpy(salesData[i].month, months[i]);
        salesData[i].sales = sales[i];
    }
    qsort(salesData, NUM_MONTHS, sizeof(struct SalesData), compareSales);

    
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month      \tSales\n");
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%s      \t$%.2f\n", salesData[i].month, salesData[i].sales);
    }
}

int main() {
    double sales[NUM_MONTHS];
    readMonthlySales(sales, "sales.txt");

    double min, max, avg;
    calculateSalesSummary(sales, &min, &max, &avg);

    generateSalesReport(sales);

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2lf\n", min);
    printf("Maximum sales: $%.2lf\n", max);
    printf("Average sales: $%.2lf\n", avg);

    generateMovingAverageReport(sales);
    generateHighestToLowestReport(sales);
    return 0;
}