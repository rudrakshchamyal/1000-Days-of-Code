import base64
import os
from flask import Flask, request, jsonify
from flask_cors import CORS

import google.generativeai as genai
import PIL.Image

app = Flask(__name__)
CORS(app)

# Initialize the AI Model
print("Setting up Gemini AI...")
# PUT YOUR FREE API KEY HERE:
genai.configure(api_key=os.getenv("GEMINI_API_KEY"))
model = genai.GenerativeModel('gemini-2.5-flash')
print("AI Model Ready!")

@app.route('/process-image', methods=['POST'])
def process_image():
    try:
        data = request.get_json()
        if not data or 'image' not in data:
            return jsonify({'status': 'error', 'message': 'No image data provided'}), 400
        
        raw_image_data = data['image']
        
        if ',' in raw_image_data:
            header, base64_string = raw_image_data.split(',', 1)
        else:
            base64_string = raw_image_data

        image_bytes = base64.b64decode(base64_string)
        
        # Save the temporary image
        output_filename = "input.png"
        with open(output_filename, "wb") as f:
            f.write(image_bytes)
            
        print(f"\n[RECEIVED] Image saved as: {output_filename}")
        
        # --- THE MAGIC HAPPENS HERE ---
        print("[PROCESSING] Sending image to Gemini AI...")
        
        # Load the image for Gemini
        img = PIL.Image.open(output_filename)
        
        # Ask Gemini to extract the math
        # Give the AI strict instructions
        prompt = """You are a strict math OCR tool. Read the handwritten math equation in this image. 
        Return ONLY the raw LaTeX code for the equation. 
        Do NOT include any conversational text like 'AI Processed successfully' or 'Here is the math'. 
        Do NOT use markdown blocks like ```latex. 
        Just the raw LaTeX string, nothing else."""
        response = model.generate_content([prompt, img])
        
        result = response.text.strip()
        
        print(f"[SUCCESS] AI found: {result}")
        
        # Send the math text back to the HTML page!
        # Extract the text the AI found
        ai_result = response.text.strip()
        
        print(f"[2/2] Success! Gemini found: {ai_result}")
        
        # Send the AI's answer back to your HTML webpage
        return jsonify({
            'status': 'success',
            'message': ai_result  # <--- MAKE SURE THIS SAYS ai_result (no quotes around it!)
        })

    except Exception as e:
        print(f"[ERROR] {str(e)}")
        return jsonify({'status': 'error', 'message': str(e)}), 500

if __name__ == '__main__':
    app.run(debug=True, port=5000)