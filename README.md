# Web3.0_Task
This code allows to book for gym and badminton facilities, see booking history of student, seperately allots monthly and half-yearly slots for gym.<br>
First it asks for roll number of the student:<br>
If the user inputs any non-integer it asks for vaid integer input again.<br>

![WhatsApp Image 2024-04-05 at 19 06 35_c34e193e](https://github.com/koushiksoma66/Web3.0_Task/assets/166048906/8e654789-9b03-47bf-9643-4b4d0074fd93)

It then asks to choose the facility the user wants to book i.e, gym or badminton and if the user is here only for checking booking history then "none" or anything other than gym and badminton can be entered for example I randomly entered "check" here.<br>

![WhatsApp Image 2024-04-05 at 21 42 23_b8cf4469](https://github.com/koushiksoma66/Web3.0_Task/assets/166048906/3d56eef4-a18f-4d4f-8d21-45fda692606c)

It's possible for the user to input any upper or lower case by mistake especially in the letter. This code ensures the input to be case in-sensitive. For example here the user entered "badmiNton" and the code still properly runs.<br>

![WhatsApp Image 2024-04-05 at 19 27 05_abc9f502](https://github.com/koushiksoma66/Web3.0_Task/assets/166048906/67547a38-1568-4cd3-812d-0e07d761a73b)

It then displays all the available slots with there respective slot number for the sport chosen and asks to choose a slot number. As it is the first student to book now, all the slots are available and the slot will be directly booked. If the user enters an slot number greater than 4 or less than 0 which doesn't exist, it outputs "Choose a valid slot". The following two screenshots shows these two cases.<br>

![WhatsApp Image 2024-04-05 at 21 49 31_e32b3e69](https://github.com/koushiksoma66/Web3.0_Task/assets/166048906/27380716-2a63-40a8-848e-986865359984)

![WhatsApp Image 2024-04-05 at 21 56 02_28d92e80](https://github.com/koushiksoma66/Web3.0_Task/assets/166048906/7143ccb0-3c11-484a-aa6b-03543765dd77)

Then it asks whether the user wants to check booking history.<br>
Entering Yes shows the booking history separetely for gym and badminton.<br>
Here we are done with a single booking.

![WhatsApp Image 2024-04-05 at 19 30 12_c878c7cf](https://github.com/koushiksoma66/Web3.0_Task/assets/166048906/7f20630b-4c7f-489e-a696-67290eee3ee0)

Now, trying to book the same slot by same or another student will not be permitted. For example here a student tried to book slot 3 of badminton which was already booked by the previous student so it shows that the slot has been already booked. And also the slot disappears from the available slots list once the booking has been made.

![WhatsApp Image 2024-04-05 at 19 49 13_24a56f39](https://github.com/koushiksoma66/Web3.0_Task/assets/166048906/dff69a89-e6af-49e7-9a1a-18a473f370d1)

Booking Gym has slighty different rules since, 3 students can book the same slot at a time as more space is available for gym whereas for badminton it is assumed that only a single badminton court is present(for the sake of simplicity) hence, booking rules for gym have been provided to the student if the student tries to book a gym slot.



