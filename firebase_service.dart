import 'package:firebase_database/firebase_database.dart';

class FirebaseService {
  final DatabaseReference _db = FirebaseDatabase.instance.ref();

  bool lightState = false;
  bool fanState = false;

  void toggleLight(bool value) {
    _db.child("home/light").set(value);
    lightState = value;
  }

  void toggleFan(bool value) {
    _db.child("home/fan").set(value);
    fanState = value;
  }
}
