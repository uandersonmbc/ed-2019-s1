CFLAGS = -Wall

video_b:
	rm -f video.mp4
	ffmpeg -framerate 1 -pattern_type glob -i 'img/bubble/*.png' -c:v libx264 -profile:v high -crf 20 -pix_fmt yuv420p bubble.mp4

video_i:
	rm -f video.mp4
	ffmpeg -framerate 5 -pattern_type glob -i 'img//*.png' -c:v libx264 -profile:v high -crf 20 -pix_fmt yuv420p insertion.mp4

video_s:
	rm -f video.mp4
	ffmpeg -framerate 5 -pattern_type glob -i 'img//*.png' -c:v libx264 -profile:v high -crf 20 -pix_fmt yuv420p selection.mp4
clean:
	rm -f img//*.png