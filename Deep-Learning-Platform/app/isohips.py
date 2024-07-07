import os
import numpy as np
import matplotlib.pyplot as plt
import cv2

def plot_contours_on_image(input_file, output_file):
    # Görüntü dosyasını oku
    image = cv2.imread(input_file, cv2.IMREAD_GRAYSCALE)
    
    # İzohips çizgilerini çiz
    plt.figure(figsize=(10, 8))
    plt.contour(image, levels=10, cmap='jet')  # 10 seviyede izohips çizgileri
    plt.colorbar()  # Renk skalası
    plt.imshow(image, cmap='gray')
    
    # Sonucu kaydet
    plt.savefig(output_file, format='jpg')
    plt.close()

def process_all_images(input_folder, output_folder):
    # Çıkış klasörünü oluştur
    os.makedirs(output_folder, exist_ok=True)
    
    # Giriş klasöründeki tüm dosyaları listele
    for filename in os.listdir(input_folder):
        # Giriş ve çıkış dosya yollarını oluştur
        input_file = os.path.join(input_folder, filename)
        output_file = os.path.join(output_folder, filename)
        
        try:
            # İzohips ekleyip kaydet
            plot_contours_on_image(input_file, output_file)
            print(f"{filename} izohips added")
        except Exception as e:
            print(f"Error processing file {filename}: {e}")

# Örnek kullanım
input_folder = 'data/images/'
output_folder = 'runs/detect/exp/isohips/'
process_all_images(input_folder, output_folder)
