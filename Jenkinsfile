pipeline {
    agent {
        dockerfile true
    }

    environment {
        BUILD_DIR = 'build'
    }

    stages {
        stage('Build') {
            steps {
                sh 'cmake -S . -DCMAKE_OSX_ARCHITECTURES=arm64 -B ${BUILD_DIR}'
                sh 'cmake --build ${BUILD_DIR}'
            }
        }

        stage('Test') {
            steps {
                sh './${BUILD_DIR}/test_repos --gtest_output=xml:test_report.xml'
            }
        }
    }

    post {
        always {
            xunit (tools: [ GoogleTest(pattern: 'test_report.xml') ], skipPublishingChecks: false)
        }
    }
}