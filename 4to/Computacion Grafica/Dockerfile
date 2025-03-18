FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    python3 \
    python3-pip \
    python3-gi \
    python3-gi-cairo \
    gir1.2-goocanvas-2.0 \
    gir1.2-gtk-3.0 \
    libcairo2-dev \
    libgirepository1.0-dev \
    gcc \
    python3-dev \
    && apt-get clean


WORKDIR /app

COPY . /app
CMD ["python3", "draw.py"]
