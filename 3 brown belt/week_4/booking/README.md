In the lecture, we wrote the TripManager class for booking a set of flights and hotels using the auxiliary classes FlightProvider and HotelProvider. Following the RAII idiom, we took the booked set to a separate Trip class. The code written in the lecture was slightly modified and placed in the files old_booking_providers.h and old_trip_manager.h

You are now invited to arrange for individual flight and hotel reservations to be RAII-style. This will simplify the Trip class: in its Cancel function, you won’t have to call up cancellations, but simply remove the elements from the vectors.

You are given new versions of the classes TripManager, Trip, FlightProvider and HotelProvider, which are in the files new_booking_providers.h and new_trip_manager.h. We renamed the Cancel function in the new classes to CancelOrComplete: it will automatically be called not only upon cancellation of the reservation, but also upon its successful completion. Now the Book and CancelOrComplete functions in the provider classes do not return and accept the BookingId, but the special class that you need to create.

Since FlightProvider and HotelProvider have the same interface, in order to avoid code duplication, we ask you to develop a template class Booking <Provider>, where FlightProvider and HotelProvider will act as a template type.

Send the booking.h file to the testing system, which:

- contains the RAII namespace
- inside the RAII namespace contains the definition of the template template Booking <Provider>

The interface of the Booking <Provider> class should become clear to you after examining the new_booking_providers.h and new_trip_manager.h files.

For the convenience of testing, we made a booking counter and the maximum allowable number of bookings with public static variables of the FlightProvider and HotelProvier classes.
