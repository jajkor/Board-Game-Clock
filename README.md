![20240101_233220](https://github.com/jajkor/Board-Game-Clock/assets/97195875/d7d79036-79e6-4e76-b0dd-342b956d4b68)

<p align="center">4 Player Board game clock</p>

<p align="center">
<a href="https://github.com/jajkor/4WD-Robot/blob/main/LICENSE"><img src=https://img.shields.io/badge/license-MIT-blue>
<a href="https://github.com/jajkor/4WD-Robot/releases"><img src=https://img.shields.io/badge/release-v1.0.0-green>
</p>

A stopwatch intended for use in board games to track the length of each player's turn in sessions of the board game Hegemony, a 4-player asymmetric politico-economic card-driven board game. 

The turn-order goes clockwise with each turn occurring asynchronously. The length of each turn is output to a character LCD display in the format of hours, minutes, seconds, and milliseconds. Each corner of the breadboard has a uniquely colored LED. The on-state denotes a player's turn and a pushbutton is used to end it. The four LEDS are connected to the Arduino by utilizing a '74ls139' decoder connected to a '74ls04' inverter. With this, each LED is mapped to a two-bit sequence thereby reducing the number of wires from four to two.

<table>
  <tr>
    <th>Color</th>
    <th>Bit String</th>
  </tr>
  <tr>
    <td>RED</td>
    <td>00</td>
  </tr>
  <tr>
    <td>YELLOW</td>
    <td>10</td>
  </tr>
  <tr>
    <td>BLUE</td>
    <td>01</td>
  </tr>
  <tr>
    <td>WHITE</td>
    <td>11</td>
  </tr>
</table>
