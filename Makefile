exe:	App.o VideoStreamer.o
	g++ -o exe `pkg-config --cflags opencv` App.o VideoStreamer.o  -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_viz -lopencv_core -L/usr/local/share/OpenCV/3rdparty/lib -lippicv

App.o:	App.cpp
	g++ -c App.cpp

VideoStreamer.o:	VideoStreamer.cpp
			g++ -c VideoStreamer.cpp	
