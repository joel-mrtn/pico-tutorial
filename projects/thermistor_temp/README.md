# Thermistor temperature

![Breadboard](/assets/thermistor_temp_bb.png)

## Formula:

$$
T = \frac{1}{\frac{1}{T_0} + \frac{\ln\left(\frac{R_t}{R}\right)}{B}}
$$

### Variables in the Formula:

- **\( $T_0$ \)**: Nominal temperature, here 25°C.
- **\( $R_t$ \)**: Resistance of the thermistor at the measured temperature.
- **\( $R$ \)**: Nominal resistance of the thermistor at the nominal temperature \( $T_0$ \), here 10.000 ohm.
- **\( $B$ \)**: Beta ( $\beta$ ) coefficient of the thermistor, which characterizes the relationship between the
  thermistor's resistance and temperature, here 3950.
