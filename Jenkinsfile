pipeline {
    agent {
        docker {
            image 'conanio/gcc10'
            args '-u root'
            customWorkspace '/tmp/jenkins'
        }
    }

    environment {
        BUILD_DIR = 'build'
        CXXFLAGS = "-w"
    }

    stages {
        stage('Build') {
            steps {
                sh 'export CXXFLAGS="-w" && cmake -S . -DCMAKE_OSX_ARCHITECTURES=arm64 -B ${BUILD_DIR}'
                sh 'export CXXFLAGS="-w" && cmake --build ${BUILD_DIR}'
            }
        }

        stage('Test') {
            steps {
                sh 'ls ./${BUILD_DIR}'
                sh './${BUILD_DIR}/test_repos --gtest_output=xml:report.xml'
            }
        }
    }

    post {
        always {
            xunit (tools: [ GoogleTest(pattern: 'test_report.xml') ], skipPublishingChecks: false)
        }
    }
}