import 'package:flutter/material.dart';
import '../services/firebase_service.dart';

class HomeScreen extends StatelessWidget {
  final FirebaseService firebase = FirebaseService();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text("Home Automation")),
      body: Column(
        children: [
          SwitchListTile(
            title: const Text("Light"),
            value: firebase.lightState,
            onChanged: firebase.toggleLight,
          ),
          SwitchListTile(
            title: const Text("Fan"),
            value: firebase.fanState,
            onChanged: firebase.toggleFan,
          ),
        ],
      ),
    );
  }
}
