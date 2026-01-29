import 'package:flutter/material.dart';
import 'screens/home_screen.dart';

void main() {
  runApp(const HomeAutomationApp());
}

class HomeAutomationApp extends StatelessWidget {
  const HomeAutomationApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: HomeScreen(),
      debugShowCheckedModeBanner: false,
    );
  }
}
